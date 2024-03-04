#ifndef _FIFO_TYPE__H_
#define _FIFO_TYPE__H_

#include <Arduino.h>
#include <FIFO.h>

template<typename T>
class FIFO_Type {

  private:
    FIFO m_fifo;
    
  public:
    FIFO_Type(const byte capacity) : m_fifo(capacity * sizeof(T))
    {
      m_fifo.clear();
    }

    void clear() {
      m_fifo.clear();
    }

    void push(const T w) {
      byte n = sizeof(T);
      T wk = w;
      while (n--) {
        m_fifo.push((byte) wk);
        wk >>= 8;
      }
    }

    T pop() {
      T w = 0;
      for (byte i = 0; i < sizeof(T); ++i) {
        w |= (T) m_fifo.pop() << (i << 3);
      }
      return w;
    }

    bool isEmpty() const {
      return m_fifo.isEmpty();
    }

    bool isFull() const {
      return m_fifo.isFull();
    }
    
};

#endif
