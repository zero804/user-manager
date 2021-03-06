project(user-manager)
cmake_minimum_required(VERSION 2.8.12)
set(PROJECT_VERSION "5.19.90")

set(QT_MIN_VERSION "5.15.0")
set(KF5_MIN_VERSION "5.74")

find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})
SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules" ${CMAKE_MODULE_PATH})

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED  COMPONENTS Core Widgets DBus)
find_package(KF5 ${KF5_MIN_VERSION} REQUIRED WidgetsAddons CoreAddons I18n Config ConfigWidgets KCMUtils KIO Auth)
find_package(PWQuality REQUIRED)

include(FeatureSummary)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDEFrameworkCompilerSettings NO_POLICY_SCOPE)
include(KDEClangFormat)
include(ECMQtDeclareLoggingCategory)

include_directories(${PWQUALITY_INCLUDE_DIR})

# Set KI18n translation domain
add_definitions(-DTRANSLATION_DOMAIN=\"user_manager\")
if (EXISTS "${CMAKE_SOURCE_DIR}/.git")
   add_definitions(-DQT_DISABLE_DEPRECATED_BEFORE=0x060000)
   add_definitions(-DKF_DISABLE_DEPRECATED_BEFORE_AND_AT=0x054200)
endif()

add_subdirectory(src)


ecm_qt_install_logging_categories(
        EXPORT USERMANAGER
        FILE user-manager.categories
        DESTINATION ${KDE_INSTALL_LOGGINGCATEGORIESDIR}
        )

# add clang-format target for all our real source files
file(GLOB_RECURSE ALL_CLANG_FORMAT_SOURCE_FILES *.cpp *.h)
kde_clang_format(${ALL_CLANG_FORMAT_SOURCE_FILES})

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
