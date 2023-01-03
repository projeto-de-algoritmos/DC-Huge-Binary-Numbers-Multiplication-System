#include "Calculator.h"

std::string normal_mutliplication(std::string X, std::string Y, double* duration) {
    std::string allSum = "";
    const int n = Y.length();

    struct timeval total_ini, total_end;

    gettimeofday(&total_ini, 0);
    for (int j = 0; j < n; ++j) { 
        int secondDigit = Y[j] - '0'; 
        if (secondDigit == 1) { 
            allSum = add(shifting(X, Y.size()-(j+1)), allSum); 
        } 
        else
            continue; 
          
    }
    gettimeofday(&total_end, 0);

    *duration = calc_time(total_ini.tv_sec, total_end.tv_sec, total_ini.tv_usec, total_end.tv_usec);

    return allSum; 
}

std::string karatsuba_mutliplication_ini(std::string X, std::string Y, double* duration){
    struct timeval total_ini, total_end;

    gettimeofday(&total_ini, 0);
    std::string res = karatsuba_mutliplication(X, Y);
    gettimeofday(&total_end, 0);

    *duration = calc_time(total_ini.tv_sec, total_end.tv_sec, total_ini.tv_usec, total_end.tv_usec);

    for (auto c : res)
        {
            if (res[0] == '0')
                res.erase(0, 1);
        }
    return res;
}

std::string karatsuba_mutliplication(std::string X, std::string Y){
    const int n = lengthController(X, Y);

    if (n == 1)
        return ((Y[0] - '0' == 1) && (X[0] - '0' == 1)) ? "1" : "0";

    const int half = n / 2;

    std::string Xl = X.substr(0, half);
    std::string Xr = X.substr(half);

    std::string Yl = Y.substr(0, half);
    std::string Yr = Y.substr(half);

    const std::string P1 = karatsuba_mutliplication(Xl, Yl);
    const std::string P2 = karatsuba_mutliplication(Xr, Yr);
    const std::string P3 = karatsuba_mutliplication(add(Xl, Xr), add(Yl, Yr));

    // return added string version
    return add(add(shifting(P1, 2 * (n - half)), P2), shifting(sub(P3, add(P1, P2)), n - (half)));
}

std::string shifting(const std::string &str, const ull &stepnum)
{
    std::string shifted(stepnum, '0');
    return str + shifted;
}

std::string sub(std::string lhs, std::string rhs){
    int length = lengthController(lhs, rhs);
    long long int diff;
    std::string result;

    for (int i = length - 1; i >= 0; i--)
    {
        diff = (lhs[i] - '0') - (rhs[i] - '0');
        if (diff >= 0)
        {
            result = ulltob(diff) + result;
        }
        else
        {
            for (int j = i - 1; j >= 0; j--)
            {
                lhs[j] = ((lhs[j] - '0') - 1) % 10 + '0';
                if (lhs[j] != '1')
                    break;
            }
            result = ulltob(diff + 2) + result;
        }
    }
    return result;
}

ull lengthController(std::string &str1, std::string &str2)
{
    const int len1 = str1.size();
    const int len2 = str2.size();
    if (len1 < len2)
    {
        const std::string nw(len2 - len1, '0');
        str1 = nw + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        const std::string novo(len1 - len2, '0');
        str2 = novo + str2;
    }
    return len1;
}

std::string add(const std::string &a, const std::string &b)
{
    std::string result = "";
    int s = 0;

    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        s += ((i >= 0) ? a[i] - '0' : 0);
        s += ((j >= 0) ? b[j] - '0' : 0);

        result = char(s % 2 + '0') + result;

        s /= 2;

        i--;
        j--;
    }

    return result;
}