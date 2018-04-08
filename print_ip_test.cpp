#define BOOST_TEST_LOG_LEVEL test_suite
#define BOOST_TEST_MODULE test_main
#include <boost/test/unit_test.hpp>

#include "print_ip.h"

BOOST_AUTO_TEST_SUITE(test_integral)

    BOOST_AUTO_TEST_CASE(test_print_ip_char_correct)
    {
        std::stringbuf out_buffer;
        std::ostream out_stream(&out_buffer);
        print_ip(char(-1),out_stream);
        BOOST_CHECK_EQUAL(out_buffer.str(),"255");
    }

/////////////////////////////////////////////////////////////////////////////

    BOOST_AUTO_TEST_CASE(test_print_ip_short_correct)
    {
        std::stringbuf out_buffer;
        std::ostream out_stream(&out_buffer);
        print_ip(short(0),out_stream);
        BOOST_CHECK_EQUAL(out_buffer.str(),"0.0");
    }

/////////////////////////////////////////////////////////////////////////////

    BOOST_AUTO_TEST_CASE(test_print_ip_int_correct)
    {
        std::stringbuf out_buffer;
        std::ostream out_stream(&out_buffer);
        print_ip(int(2130706433),out_stream);
        BOOST_CHECK_EQUAL(out_buffer.str(),"127.0.0.1");
    }

/////////////////////////////////////////////////////////////////////////////

    BOOST_AUTO_TEST_CASE(test_print_ip_long_correct)
    {
        std::stringbuf out_buffer;
        std::ostream out_stream(&out_buffer);
        print_ip(long(8875824491850138409),out_stream);
        BOOST_CHECK_EQUAL(out_buffer.str(),"123.45.67.89.101.112.131.41");
    }

BOOST_AUTO_TEST_SUITE_END()

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(test_string)

    BOOST_AUTO_TEST_CASE(test_print_ip_string_correct)
    {
        std::stringbuf out_buffer;
        std::ostream out_stream(&out_buffer);
        print_ip(std::string{"123.45.67.89.101.112.131.41"},out_stream);
        BOOST_CHECK_EQUAL(out_buffer.str(),"123.45.67.89.101.112.131.41");
    }

BOOST_AUTO_TEST_SUITE_END()

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(test_containers)

    BOOST_AUTO_TEST_CASE(test_print_ip_vector_char_correct)
    {
        std::stringbuf out_buffer;
        std::ostream out_stream(&out_buffer);
        std::vector<char> v = {1,static_cast<char>(244),-1};
        print_ip(v,out_stream);
        BOOST_CHECK_EQUAL(out_buffer.str(),"1..244..255");
    }
    
    BOOST_AUTO_TEST_CASE(test_print_ip_vector_int_correct)
    {
        std::stringbuf out_buffer;
        std::ostream out_stream(&out_buffer);
        std::vector<int> v = {1,1675,4598};
        print_ip(v,out_stream);
        BOOST_CHECK_EQUAL(out_buffer.str(),"0.0.0.1..0.0.6.139..0.0.17.246");
    }

/////////////////////////////////////////////////////////////////////////////

    BOOST_AUTO_TEST_CASE(test_print_ip_list_short_correct)
    {
        std::stringbuf out_buffer;
        std::ostream out_stream(&out_buffer);
        std::list<short> list = {0,457,-254};
        print_ip(list,out_stream);
        BOOST_CHECK_EQUAL(out_buffer.str(),"0.0..1.201..255.2");
    }

/////////////////////////////////////////////////////////////////////////////

    BOOST_AUTO_TEST_CASE(test_print_ip_list_long_correct)
    {
        std::stringbuf out_buffer;
        std::ostream out_stream(&out_buffer);
        std::list<long> list = {8875824491850138409,887582449185013840};
        print_ip(list,out_stream);
        BOOST_CHECK_EQUAL(out_buffer.str(),"123.45.67.89.101.112.131.41..12.81.83.136.240.139.64.80");
    }

BOOST_AUTO_TEST_SUITE_END()

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(test_containers)

    BOOST_AUTO_TEST_CASE(test_print_ip_tuple_correct)
    {
        std::stringbuf out_buffer;
        std::ostream out_stream(&out_buffer);
        auto tuple = std::make_tuple(static_cast<long>(8875824491850138409),std::vector<char>{1,2},std::string{"111.111"});
        print_ip(tuple,out_stream);
        BOOST_CHECK_EQUAL(out_buffer.str(),"123.45.67.89.101.112.131.41...1..2...111.111");
    }

BOOST_AUTO_TEST_SUITE_END()