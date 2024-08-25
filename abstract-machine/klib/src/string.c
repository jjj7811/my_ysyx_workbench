#include <klib-macros.h>
#include <klib.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  // panic("Not implemented");
  size_t len = 0;
  while (*(s + len) != '\0') {
    len++;
  }
  return len;
}

char *strcpy(char *dst, const char *src) {
  // panic("Not implemented");
  size_t len = 0;
  while (*(src + len) != '\0') {
    *(dst + len) = *(src + len);
    len++;
  }
  *(dst + len) = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  // panic("Not implemented");
  size_t len = 0;
  for (len = 0; len < n && *(src + len) != '\0'; len++) {
    *(dst + len) = *(src + len);
  }
  for (; len < n; len++) {
    *(dst + len) = '\0';
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  // panic("Not implemented");
  size_t dst_len = strlen(dst);
  size_t i;

  for (i = 0; *(src + i) != '\0'; i++) dst[dst_len + i] = src[i];
  dst[dst_len + i] = '\0';
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  // panic("Not implemented");
  while (*s1 == *s2) {
    if (*s1 == '\0') return 0;
    s1++;
    s2++;
  }
  return (*s1 - *s2);
}

int strncmp(const char *s1, const char *s2, size_t n) {
  // panic("Not implemented");
  int i = 0;
  for (; i < n && s1[i] != '\0' && s2[i] != '\0'; i++) {
    if (s1[i] != s2[i]) {
      return s1[i] - s2[i];  // 如果当前位置的两个字符不相等，返回它们的差值。
    }
  }

  if (i <= n) {
    return s1[i] - s2[i];
  }

  return 0;
}

void *memset(void *s, int c, size_t n) {
  // panic("Not implemented");
  void *ret = s;
  while (n--) {
    *(char *)s = c;
    s = (char *)s + 1;
  }
  return ret;
}

void *memmove(void *dest, const void *src, size_t n) {
  unsigned char *d = (unsigned char *)dest;
   unsigned char *s = ( unsigned char *)src;
  if (d < s) {
    for (size_t i = 0; i < n; i++) {
      d[i] = s[i];
    }
  } else {
    for (size_t i = n; i != 0; i--) {
      d[i - 1] = s[i - 1];
    }
  }
  return dest;
}

// void *memmove(void *dst, const void *src, size_t n) {
//   // panic("Not implemented");
//   void *ret = dst;
//   if (dst < src) {
//     while (n--) {
//       *(char *)dst = *(char *)src;
//       dst = (char *)dst + 1;
//       src = (char *)src + 1;
//     }
//   } else {
//     while (n--) {
//       *((char *)dst + n) = *((char *)src + n);
//     }
//   }
//   return ret;
// }

void *memcpy(void *out, const void *in, size_t n) {
  // panic("Not implemented");
  void *ret = out;
  while (n--) {
    *(char *)out = *(char *)in;
    out = (char *)out + 1;
    in = (char *)in + 1;
  }
  return ret;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  // panic("Not implemented");
  while (n--) {
    if (*(char *)s1 > *(char *)s2)
      return 1;
    else if (*(char *)s1 < *(char *)s2)
      return -1;
    else {
      s1 = (char *)s1 + 1;
      s2 = (char *)s2 + 1;
    }
  }
  return 0;
}

#endif
