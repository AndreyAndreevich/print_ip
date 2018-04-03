#define BOOST_TEST_LOG_LEVEL test_suite
#define BOOST_TEST_MODULE test_main
#include <boost/test/unit_test.hpp>

#include "print_ip.h"

BOOST_AUTO_TEST_CASE(test_print_ip_char_correct)
{
    std::stringbuf out_buffer;
    std::ostream out_stream(&out_buffer);
    print_ip(char(-1),out_stream);
    BOOST_CHECK_EQUAL(out_buffer,"255");
}

BOOST_AUTO_TEST_CASE(test_print_ip_short_correct)
{
    std::stringbuf out_buffer;
    std::ostream out_stream(&out_buffer);
    print_ip(short(0),out_stream);
    BOOST_CHECK_EQUAL(out_buffer,"0.0");
}

BOOST_AUTO_TEST_CASE(test_print_ip_int_correct)
{
    std::stringbuf out_buffer;
    std::ostream out_stream(&out_buffer);
    print_ip(int(2130706433),out_stream);
    BOOST_CHECK_EQUAL(out_buffer,"127.0.0.1");
}

BOOST_AUTO_TEST_CASE(test_print_ip_long_correct)
{
    std::stringbuf out_buffer;
    std::ostream out_stream(&out_buffer);
    print_ip(long(8875824491850138409),out_stream);
    BOOST_CHECK_EQUAL(out_buffer,"123.45.67.89.101.112.131.41");
}
/*
BOOST_AUTO_TEST_CASE(test_print_ip_string_correct)
{
    std::stringbuf out_buffer;
    std::ostream out_stream(&out_buffer);
    print_ip(long(8875824491850138409),out_stream);
    BOOST_CHECK_EQUAL(out_buffer,"123.45.67.89.101.112.131.41");
}

BOOST_AUTO_TEST_CASE(test_print_ip_vector_correct)
{
    std::stringbuf out_buffer;
    std::ostream out_stream(&out_buffer);
    print_ip(long(8875824491850138409),out_stream);
    BOOST_CHECK_EQUAL(out_buffer,"123.45.67.89.101.112.131.41");
}

BOOST_AUTO_TEST_CASE(test_print_ip_list_correct)
{
    std::stringbuf out_buffer;
    std::ostream out_stream(&out_buffer);
    print_ip(long(8875824491850138409),out_stream);
    BOOST_CHECK_EQUAL(out_buffer,"123.45.67.89.101.112.131.41");
}

BOOST_AUTO_TEST_CASE(test_print_ip_tuple_correct)
{
    std::stringbuf out_buffer;
    std::ostream out_stream(&out_buffer);
    print_ip(long(8875824491850138409),out_stream);
    BOOST_CHECK_EQUAL(out_buffer,"123.45.67.89.101.112.131.41");
}
*/