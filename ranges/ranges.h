#pragma once

#include <iostream>

#include <boost/icl/continuous_interval.hpp>
#include <boost/icl/closed_interval.hpp>
#include <boost/icl/interval_set.hpp>

//! https://www.boost.org/doc/libs/1_79_0/libs/icl/doc/html/index.html#boost_icl.introduction.definition_and_basic_example
template<class T>
class ranges_t {
    public:
    boost::icl::interval_set<T> _ranges;

    typedef typename decltype(_ranges)::interval_type interval_type;

    void add(const T min, const T max) {
        std::cout << "Adding (" << min << ", " << max << ")\n";
        _ranges.insert(interval_type::closed(min, max));
    }

    void sub(const T min, const T max) {
        std::cout << "Subscracting (" << min << ", " << max << ")\n";
        _ranges -= interval_type::closed(min, max);
    }

    void dump(std::ostream& ostr) const {
        if (_ranges.empty())
            ostr << "<empty>";

        for (const auto &r: _ranges)
            ostr << r << ", ";
    }
};

// template<class T>
// std::ostream& operator<<(std::ostream& ostr, const boost::icl::closed_interval<T> &i) {
//     ostr << i.
// }
//     ostr << "ranges: ";
// }

template<class T>
std::ostream& operator<<(std::ostream& ostr, const ranges_t<T>& r) {
    ostr << "ranges: ";
    r.dump(ostr);
    return ostr;
}