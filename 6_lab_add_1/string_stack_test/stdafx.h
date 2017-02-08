#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <boost/algorithm/string/replace.hpp>

///=======================================
#define BOOST_TEST_INCLUDED
#pragma warning (disable:4702)
#include <boost/test/unit_test.hpp>
///=======================================

#include <boost/test/output_test_stream.hpp>

#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
