//$$CDS-header$$

#ifndef CDSLIB_COMPILER_ICL_DEFS_H
#define CDSLIB_COMPILER_ICL_DEFS_H
//@cond

// Compiler version
#ifdef __ICL
#   define CDS_COMPILER_VERSION    __ICL
#else
#   define CDS_COMPILER_VERSION    __INTEL_COMPILER
#endif

// Compiler name
// Supported compilers: MS VC 2008, 2010, 2012
//
#   define  CDS_COMPILER__NAME  "Intel C++"
#   define  CDS_COMPILER__NICK  "icl"

// OS name
#if defined(_WIN64)
#   define CDS_OS_INTERFACE CDS_OSI_WINDOWS
#   define CDS_OS_TYPE      CDS_OS_WIN64
#   define CDS_OS__NAME     "Win64"
#   define CDS_OS__NICK     "Win64"
#elif defined(_WIN32)
#   define CDS_OS_INTERFACE CDS_OSI_WINDOWS
#   define CDS_OS_TYPE      CDS_OS_WIN32
#   define CDS_OS__NAME     "Win32"
#   define CDS_OS__NICK     "Win32"
#elif defined( __linux__ )
#   define CDS_OS_INTERFACE     CDS_OSI_UNIX
#   define CDS_OS_TYPE          CDS_OS_LINUX
#   define CDS_OS__NAME         "linux"
#   define CDS_OS__NICK         "linux"
#endif

// Processor architecture
#if defined(_M_X64) || defined(_M_AMD64) || defined(__amd64__) || defined(__amd64)
#   define CDS_BUILD_BITS       64
#   define CDS_PROCESSOR_ARCH   CDS_PROCESSOR_AMD64
#   define CDS_PROCESSOR__NAME  "AMD64"
#   define CDS_PROCESSOR__NICK  "amd64"
#elif defined(_M_IX86) || defined(__i386__) || defined(__i386)
#   define CDS_BUILD_BITS       32
#   define CDS_PROCESSOR_ARCH   CDS_PROCESSOR_X86
#   define CDS_PROCESSOR__NAME  "Intel x86"
#   define CDS_PROCESSOR__NICK  "x86"
#else
#   define CDS_BUILD_BITS        -1
#   define CDS_PROCESSOR_ARCH    CDS_PROCESSOR_UNKNOWN
#   define CDS_PROCESSOR__NAME    "<<Undefined>>"
#   error Intel C++ compiler is supported for x86 only
#endif

#if CDS_OS_INTERFACE == CDS_OSI_WINDOWS
#   define  __attribute__( _x )
#   define  CDS_STDCALL    __stdcall
#else
#   if CDS_PROCESSOR_ARCH == CDS_PROCESSOR_X86
#       define CDS_STDCALL __attribute__((stdcall))
#   else
#       define CDS_STDCALL
#   endif
#endif

#if CDS_OS_INTERFACE == CDS_OSI_WINDOWS
#   ifdef CDS_BUILD_LIB
#       define CDS_EXPORT_API          __declspec(dllexport)
#   else
#       define CDS_EXPORT_API          __declspec(dllimport)
#   endif
#endif

#if CDS_OS_INTERFACE == CDS_OSI_WINDOWS
#   define alignof     __alignof
#else
#   define alignof __alignof__
#endif

#define CDS_CONSTEXPR    constexpr

#define CDS_NOEXCEPT_SUPPORT        noexcept
#define CDS_NOEXCEPT_SUPPORT_(expr) noexcept(expr)

// C++11 inline namespace
#define CDS_CXX11_INLINE_NAMESPACE_SUPPORT

// Inheriting constructors
#define CDS_CXX11_INHERITING_CTOR

// *************************************************
// Alignment macro

#if CDS_OS_INTERFACE == CDS_OSI_WINDOWS
#   define CDS_TYPE_ALIGNMENT(n)     __declspec( align(n) )
#   define CDS_DATA_ALIGNMENT(n)     __declspec( align(n) )
#   define CDS_CLASS_ALIGNMENT(n)    __declspec( align(n) )
#else
#   define CDS_TYPE_ALIGNMENT(n)   __attribute__ ((aligned (n)))
#   define CDS_CLASS_ALIGNMENT(n)  __attribute__ ((aligned (n)))
#   define CDS_DATA_ALIGNMENT(n)   __attribute__ ((aligned (n)))
#endif

// Attributes
#if CDS_OS_INTERFACE == CDS_OSI_WINDOWS
#   define CDS_DEPRECATED( reason ) __declspec(deprecated( reason ))
#else
#   define CDS_DEPRECATED( reason ) __attribute__((deprecated( reason )))
#endif

#include <cds/compiler/icl/compiler_barriers.h>

//@endcond
#endif // #ifndef CDSLIB_COMPILER_VC_DEFS_H
