# - Try to find pwquality
# Once done this will define
#  PWQUALITY_FOUND - System has pwquality
#  PWQUALITY_INCLUDE_DIRS - The pwquality include directories
#  PWQUALITY_LIBRARIES - The libraries needed to use pwquality

find_package(PkgConfig REQUIRED)

pkg_check_modules(PKG_PWQUALITY pwquality)

find_path(PWQUALITY_INCLUDE_DIR pwquality.h
          PATHS
          ${PKG_PWQUALITY_INCLUDE_DIRS})

find_library(PWQUALITY_LIBRARY NAMES pwquality
             PATHS
             ${PKG_PWQUALITY_LIBRARY_DIRS})

set(PWQUALITY_LIBRARIES ${PWQUALITY_LIBRARY} )
set(PWQUALITY_INCLUDE_DIRS ${PWQUALITY_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set  PWQUALITY_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(pwquality  DEFAULT_MSG
                                  PWQUALITY_LIBRARY PWQUALITY_INCLUDE_DIR)

mark_as_advanced(PWQUALITY_INCLUDE_DIR PWQUALITY_LIBRARY )
