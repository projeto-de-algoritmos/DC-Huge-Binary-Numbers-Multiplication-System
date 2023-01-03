#pragma once
#include <string>
#include <stack>
#include <algorithm>
#include <sys/time.h>

typedef unsigned long long int ull;

std::string btod(std::string b_num);
std::string dtob(std::string d_num);
std::string div_str_b2(std::string d_num);
std::string ulltob(ull num);
double calc_time(__time_t sec_ini, __time_t sec_end, __suseconds_t usec_ini, __suseconds_t usec_end);