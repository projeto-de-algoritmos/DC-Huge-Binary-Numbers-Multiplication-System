#include "Conversions.h"

std::string btod(std::string bn)
{
    std::string res;

    while (!bn.empty())
    {
        int r = 0;
        std::string x = "";

        for (auto b : bn)
        {
            if(b != '1' && b != '0') return "Not a binary number";
            r = 2 * r + (b - '0');

            if (r >= 10)
            {
                x += "1";
                r -= 10;
            }
            else
            {
                x += "0";
            }
        }

        for (auto c : x)
        {
            if (x[0] == '0')
                x.erase(0, 1);
        }

        res = std::to_string(r) + res;
        bn = x;
    }

    return res;
}

std::string dtob(std::string d_num){
    std::stack <char>p;
    
    while(!d_num.empty()){
        if(d_num.back() > '0'+9 || d_num.back() < '0') return "Not a decimal number";
        if((d_num.back() - '0')&1){
            p.push('1');
        }
        else p.push('0');
        d_num = div_str_b2(d_num);
    }

    std::string res;

    while (!p.empty())
    {
       res.push_back(p.top());
       p.pop();
    }
    
    return res;
};

std::string div_str_b2(std::string d_num){
    int next_add = 0, i=0;
    for(auto c : d_num){
        int add = next_add;
        int digit = c - '0';

        if(digit&1){
            next_add = 5;
        }else next_add = 0;

        digit /= 2;
        digit += add;

        d_num[i++] = '0' + digit;
    }

    if (d_num[0] == '0') d_num.erase(0, 1);

    return d_num;
}

std::string ulltob(ull number){
    if (number <= 0)
        return "0";
    else
    {
        std::string result;
        result.reserve(64 - __builtin_clzll(number));
        int i = 0;
        while (number > 0)
        {
            result.push_back((number & 1) + '0');
            number /= 2;
            i++;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
}

double calc_time(__time_t sec_ini, __time_t sec_end, __suseconds_t usec_ini, __suseconds_t usec_end){
	return (sec_end + (double) usec_end/1000000) - (sec_ini + (double) usec_ini/1000000);
}