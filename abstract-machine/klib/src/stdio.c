#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
#define INT_MAX 1024


int itoa(int value, char *string, int radix) {
  if (radix != 10) {
    // 仅支持十进制转换
    return -1;
  }

  // 处理负数
  int isNegative = value < 0;
  if (isNegative) {
    value = -value;
  }

  char *ptr = string;
  do {
    int digit = value % 10;
    *ptr++ = (digit < 10) ? ('0' + digit) : 'A' + (digit - 10);
    value /= 10;
  } while (value != 0);

  if (isNegative) {
    *ptr++ = '-';
  }
  *ptr = '\0';

  // 反转字符串
  int length = ptr - string;
  for (int i = 0; i < length / 2; i++) {
    char temp = string[i];
    string[i] = string[length - 1 - i];
    string[length - 1 - i] = temp;
  }

  return length;
}

// void ftoa(double value, char *buffer, int precision) {
//   // 处理负数
//   if (value < 0) {
//     *buffer++ = '-';
//     value = -value;
//   }

//   // 处理整数部分
//   int intPart = (int)value;
//   value -= intPart;

//   // 将整数部分转换为字符串
//   char intBuf[20];
//   itoa(intPart, intBuf, 10);
//   strcpy(buffer, intBuf);
//   buffer += strlen(intBuf);

//   // 添加小数点
//   *buffer++ = '.';

//   // 处理小数部分
//   for (int i = 0; i < precision; i++) {
//     value *= 10;
//     int digit = (int)value;
//     *buffer++ = '0' + digit;
//     value -= digit;
//   }

//   // 结束字符串
//   *buffer = '\0';
// }

int printf(const char *fmt, ...) {
  char buffer[INT_MAX];  // 临时缓冲区
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(buffer, fmt, ap);
  va_end(ap);
  // char *p = buffer;
  // putch(*p);
  // for (char *p = buffer; *p != '\0'; p++) {
  //   putch(*p);
  // }
  putstr(buffer);
  // putch('b');
  return ret;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  const char *p;
  char *s;
  char buf[64];

  for (p = fmt; *p != '\0'; p++) {
    if (*p != '%') {
      *out++ = *p;
      continue;
    }

    switch (*++p) {
      case 'c': {
        char val = (char)va_arg(ap, int);
        *out++ = val;
        break;
      }
      case 'd': {
        int val = va_arg(ap, int);
        itoa(val, buf, 10);
        strcpy(out, buf);
        out += strlen(buf);
        break;
      }
      case 's': {
        s = va_arg(ap, char *);
        strcpy(out, s);
        out += strlen(s);
        break;
      }
      // case 'f': {
      //   double val = va_arg(ap, double);
      //   ftoa(val, buf, 6); // 假设小数部分精度为6
      //   strcpy(out, buf);
      //   out += strlen(buf);
      //   break;
      // }
      default: {
        *out++ = '%';
        *out++ = *p;
        break;
      }
    }
  }
  *out = '\0';
  return out - (char *)fmt;
}

int sprintf(char *out, const char *fmt, ...) {
  // panic("Not implemented");
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(out, fmt, ap);
  // putstr(out);
  va_end(ap);
  return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsnprintf(out, n, fmt, ap);
  // putstr(out);
  va_end(ap);
  return ret;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  const char *p;
  char *s;
  size_t total_written = 0;

  for (p = fmt; *p != '\0'; p++) {
    if (*p != '%') {
      if (total_written < n - 1) {
        *out++ = *p;
        total_written++;
      }
      continue;
    }

    switch (*++p) {
      case 'c': {
        char val = (char)va_arg(ap, int);
        if (total_written < n - 1) {
          *out++ = val;
          total_written++;
        }
        break;
      }
      case 'd': {
        int val = va_arg(ap, int);
        char buf[20];
        int len = itoa(val, buf, 10);
        if (total_written + len < n) {
          strcpy(out, buf);
          out += len;
          total_written += len;
        } else {
          size_t copy_len = n - 1 - total_written;
          strncpy(out, buf, copy_len);
          out += copy_len;
          total_written += copy_len;
        }
        break;
      }
      case 's': {
        s = va_arg(ap, char *);
        size_t len = strlen(s);
        if (total_written + len < n) {
          strcpy(out, s);
          out += len;
          total_written += len;
        } else {
          size_t copy_len = n - 1 - total_written;
          strncpy(out, s, copy_len);
          out += copy_len;
          total_written += copy_len;
        }
        break;
      }
      default: {
        if (total_written < n - 1) {
          *out++ = *p;
          total_written++;
        }
        break;
      }
    }
  }

  if (n > 0) {
    *out = '\0';
  }

  return total_written;
}

#endif
