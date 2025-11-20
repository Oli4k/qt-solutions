cmake_minimum_required(VERSION 3.5)

project(QtPropertyBrowser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(QTPROPERTYBROWSER_SOURCES
    src/qtpropertybrowser.cpp
    src/qtpropertymanager.cpp
    src/qteditorfactory.cpp
    src/qtvariantproperty.cpp
    src/qttreepropertybrowser.cpp
    src/qtbuttonpropertybrowser.cpp
    src/qtgroupboxpropertybrowser.cpp
    src/qtpropertybrowserutils.cpp
)

set(QTPROPERTYBROWSER_HEADERS
    src/qtpropertybrowser.h
    src/qtpropertymanager.h
    src/qtpropertymanager_p.h
    src/qteditorfactory.h
    src/qteditorfactory_p.h
    src/qtvariantproperty.h
    src/qttreepropertybrowser.h
    src/qttreepropertybrowser_p.h
    src/qtbuttonpropertybrowser.h
    src/qtgroupboxpropertybrowser.h
    src/qtpropertybrowserutils_p.h
)

qt5_wrap_cpp(QTPROPERTYBROWSER_MOC ${QTPROPERTYBROWSER_HEADERS})

# MOC files are included in source files, don't compile them separately
set_source_files_properties(${QTPROPERTYBROWSER_MOC} PROPERTIES HEADER_FILE_ONLY TRUE)

add_library(QtPropertyBrowser STATIC
    ${QTPROPERTYBROWSER_SOURCES}
    ${QTPROPERTYBROWSER_HEADERS}
    ${QTPROPERTYBROWSER_MOC}
)

# Disable AUTOMOC - we handle .moc includes manually in source files  
set_property(TARGET QtPropertyBrowser PROPERTY AUTOMOC OFF)
# Create .moc symlinks for all MOC files that are included in source files
set(MOC_FILES_TO_LINK
    "${CMAKE_CURRENT_SOURCE_DIR}/src/qtpropertymanager.moc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/qteditorfactory.moc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/qttreepropertybrowser.moc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/qtpropertybrowser.moc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/qtvariantproperty.moc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/qtbuttonpropertybrowser.moc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/qtgroupboxpropertybrowser.moc"
)
add_custom_command(OUTPUT ${MOC_FILES_TO_LINK}
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_CURRENT_SOURCE_DIR}/src"
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_BINARY_DIR}/qtOgitor/QtPropertyBrowser/qtpropertybrowser/src/moc_qtpropertymanager.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/qtpropertymanager.moc"
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_BINARY_DIR}/qtOgitor/QtPropertyBrowser/qtpropertybrowser/src/moc_qteditorfactory.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/qteditorfactory.moc"
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_BINARY_DIR}/qtOgitor/QtPropertyBrowser/qtpropertybrowser/src/moc_qttreepropertybrowser.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/qttreepropertybrowser.moc"
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_BINARY_DIR}/qtOgitor/QtPropertyBrowser/qtpropertybrowser/src/moc_qtpropertybrowser.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/qtpropertybrowser.moc"
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_BINARY_DIR}/qtOgitor/QtPropertyBrowser/qtpropertybrowser/src/moc_qtvariantproperty.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/qtvariantproperty.moc"
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_BINARY_DIR}/qtOgitor/QtPropertyBrowser/qtpropertybrowser/src/moc_qtbuttonpropertybrowser.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/qtbuttonpropertybrowser.moc"
    COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_BINARY_DIR}/qtOgitor/QtPropertyBrowser/qtpropertybrowser/src/moc_qtgroupboxpropertybrowser.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/qtgroupboxpropertybrowser.moc"
    DEPENDS ${QTPROPERTYBROWSER_MOC}
    COMMENT "Creating .moc symlinks"
)
add_custom_target(QtPropertyBrowser_moc_files ALL DEPENDS ${MOC_FILES_TO_LINK})
add_dependencies(QtPropertyBrowser QtPropertyBrowser_moc_files)

target_include_directories(QtPropertyBrowser PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}/src
)

target_link_libraries(QtPropertyBrowser
    Qt5::Core
    Qt5::Widgets
)

set_target_properties(QtPropertyBrowser PROPERTIES
    FOLDER QtPropertyBrowser
)

