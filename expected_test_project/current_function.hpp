#pragma once
#ifdef _MSC_VER
#define E_CURRENT_FUNCTION __FUNCSIG__
#else
#define E_CURRENT_FUNCTION __PRETTY_FUNCTION__
#endif
