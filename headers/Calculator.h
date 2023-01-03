#pragma once
#include <string>
#include <vector>
#include <cstring>
#include "Conversions.h"

std::string normal_mutliplication(std::string X, std::string Y, double* duration);
std::string karatsuba_mutliplication_ini(std::string X, std::string Y, double* duration);
std::string karatsuba_mutliplication(std::string X, std::string Y);
std::string shifting(const std::string &str, const ull &stepnum);
std::string sub(std::string lhs, std::string rhs);
ull lengthController(std::string &str1, std::string &str2);
std::string add(const std::string &a, const std::string &b);
