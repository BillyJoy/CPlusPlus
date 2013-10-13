// Last Update:2013-09-26 19:17:19
/**
 * @file tuple.cpp
 * @brief 
 * @author maoxing63570@gmail.com
 * @version 0.1.00
 * @date 2013-09-26
 */
#include <iostream>
#include <tuple>
#include <string>
#include <functional>
using namespace std;

int main(int argc, char* argv[])
{
    tuple<int, float, string> t1(41, 6.3, "nico");
    cout << get<0>(t1) << " ";
    cout << get<1>(t1) << " ";
    cout << get<2>(t1) << endl;

    auto t2 = make_tuple(22, 44, "nico");
    get<1>(t1) = get<1>(t2);

    if (t1 < t2)
    {
        t1 = t2;
    }

    cout << get<0>(t1) << " ";
    cout << get<1>(t1) << " ";
    cout << get<2>(t1) << endl;

    string s;
    auto x = make_tuple(ref(s));
    get<0>(x) = "my value";

    cout << get<0>(x) << endl;
    cout << "s:=" << s << endl;

    tuple<int, float, string> t(77, 1.1, "more light");
    int i;
    float f;
    string s1;
    // make_tuple(ref(i), ref(f), ref(s1)) = t;
    tie(i, f, s1) = t;
    cout << "i:="<< i << " f:=" << f << " s1:=" << s1 << endl;

    typedef tuple<int, float, string> TupleType;
    tuple_size<TupleType>::value;
    // tuple_element<1, TupleType>::type;
    int n;
    auto tt = tuple_cat(make_tuple(42, 7.7, "hello"), tie(n));
    return 0;
}
