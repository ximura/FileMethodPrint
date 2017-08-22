#pragma once



constexpr const char* str_end(const char *str) {
  return *str ? str_end(str + 1) : str;
}

constexpr bool str_slant(const char *str) {
  return *str == '/' || *str == '\\' ? true : (*str ? str_slant(str + 1) : false);
}

constexpr const char* r_slant(const char* str) {
  return *str == '/' || *str == '\\' ? (str + 1) : r_slant(str - 1);
}

constexpr const char* file_name(const char* str) {
  return str_slant(str) ? r_slant(str_end(str)) : str;
}

#define Trace { constexpr const char* fileName = file_name(__FILE__);  fprintf(stdout, "[%s:%s]\n", fileName, __func__);}
