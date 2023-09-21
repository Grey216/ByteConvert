if (UNIT_TEST)
	message(STATUS "Configuring GoogleTest")
	add_subdirectory(GTest)
endif()

if (MAIN_TEST)
	message(STATUS "Configuring MainTest")
	add_subdirectory(MainTest)
endif()
