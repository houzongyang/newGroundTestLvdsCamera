/**
 * @file      ringBuffer.cpp
 * @author    徐笑寒 (milurx@163.com)
 * @date      2026-04-2
 * @copyright Copyright (c) 2026 上海国科航星量子科技有限公司. All rights reserved.
 */

#include "RingBuffer.h"

RingBuffer::RingBuffer(size_t capacity) : m_capacity(capacity) {
    m_buffer = new uchar[capacity];
}

RingBuffer::~RingBuffer() {
    delete[] m_buffer;
}

bool RingBuffer::push(const QByteArray &data) {
    QMutexLocker locker(&m_mutex);

    const size_t dataSize = static_cast<size_t>(data.size());
    if (dataSize == 0) return false;

    const size_t spaceBeforeWrap = m_capacity - m_writePos;
    const size_t writeSize = qMin(dataSize, spaceBeforeWrap);

    memcpy(m_buffer + m_writePos, data.constData(), writeSize);
    if (writeSize < dataSize) {
        memcpy(m_buffer, data.constData() + writeSize, dataSize - writeSize);
    }

    m_writePos = (m_writePos + dataSize) % m_capacity;

    m_notEmpty.wakeAll();
    return true;
}

QByteArray RingBuffer::peek(size_t maxSize) const {
    QMutexLocker locker(&m_mutex);

    size_t avail = (m_writePos >= m_readPos)
                 ? (m_writePos - m_readPos)
                 : (m_capacity - m_readPos + m_writePos);
    const size_t readSize = qMin(maxSize, avail);

    QByteArray result;
    result.resize(static_cast<int>(readSize));

    if (m_readPos + readSize <= m_capacity) {
        memcpy(result.data(), m_buffer + m_readPos, readSize);
    } else {
        const size_t part1 = m_capacity - m_readPos;
        memcpy(result.data(), m_buffer + m_readPos, part1);
        memcpy(result.data() + part1, m_buffer, readSize - part1);
    }
    return result;
}




QByteArray RingBuffer::pop(size_t maxSize) {
    QMutexLocker locker(&m_mutex);

    while (m_readPos == m_writePos) {
        m_notEmpty.wait(&m_mutex);
    }

    size_t avail = (m_writePos >= m_readPos)
                 ? (m_writePos - m_readPos)
                 : (m_capacity - m_readPos + m_writePos);
    const size_t readSize = qMin(maxSize, avail);

    QByteArray result;
    result.resize(static_cast<int>(readSize));

    if (m_readPos + readSize <= m_capacity) {
        memcpy(result.data(), m_buffer + m_readPos, readSize);
        m_readPos = (m_readPos + readSize) % m_capacity;
    } else {
        const size_t part1 = m_capacity - m_readPos;
        memcpy(result.data(), m_buffer + m_readPos, part1);
        memcpy(result.data() + part1, m_buffer, readSize - part1);
        m_readPos = readSize - part1;
    }
    return result;
}

size_t RingBuffer::available() const {
    QMutexLocker locker(&m_mutex);
    return (m_writePos >= m_readPos)
        ? (m_writePos - m_readPos)
        : (m_capacity - m_readPos + m_writePos);
}

bool RingBuffer::isEmpty() const
{
    return m_writePos == m_readPos;  // 读写指针重合时为空
}

