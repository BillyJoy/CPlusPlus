// Last Update:2013-09-26 20:59:58
/**
 * @file tuple_io.h
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-09-26
 */

#ifndef TUPLE_IO_H
#define TUPLE_IO_H
#include <iostream>
#include <tuple>
template<int IDX, int MAX, typename... Args>
struct PRINT_TUPLE
{
    static void print(std::ostream& strm, const std::tuple<Args...>& t)
    {
        strm << std::get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
        PRINT_TUPLE<IDX + 1, MAX, Args...>::print(strm, t);
    }
};

template<int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...>
{
    static void print(std::ostream& strm, const std::tuple<Args...>& t)
    {
        // we get nothing to do here
    }
};

template<typename ...Args>
std::ostream& operator<< (std::ostream& strm, const std::tuple<Args...>& t)
{
    strm << "[";
    PRINT_TUPLE<0, sizeof ...(Args), Args...>::print(strm, t);
    strm << "]";
    return strm;
}
#endif  /*TUPLE_IO_H*/
