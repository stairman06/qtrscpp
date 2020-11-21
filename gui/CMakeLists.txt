set(CMAKE_CXX_STANDARD 14)
find_package(Qt5 COMPONENTS Qml Quick Gui Widgets)

qt5_add_resources(qml_QRC qml.qrc)

add_executable(gui WIN32 main.cpp ${qml_QRC})
target_link_libraries(gui PUBLIC library-rs Qt5::Qml Qt5::Quick Qt5::Widgets)
target_include_directories(gui PUBLIC ${PROJECT_BINARY_DIR})

install(TARGETS gui DESTINATION bin)

if(WIN32)
  get_target_property(qmake_exe Qt5::qmake IMPORTED_LOCATION)
  get_filename_component(QT_BIN "${qmake_exe}" DIRECTORY)
  find_program(WINDEPLOYQT_EXE windeployqt HINTS "${QT_BIN}")

  add_custom_command(TARGET gui POST_BUILD
    COMMAND set "PATH=${QT_BIN};%PATH%"
    COMMAND "${WINDEPLOYQT_EXE}" --no-opengl-sw --no-qmltooling --no-translations --qmldir ${CMAKE_CURRENT_SOURCE_DIR} "$<TARGET_FILE:gui>"
    COMMENT "Deploying"
  )
endif()