define_example_program(test.scratch.versions main.cpp)

if(b64_FOUND)

	target_link_libraries(test.scratch.versions
		PRIVATE
			b64::core
	)
endif()

if(TARGET xTests::core)

	target_link_libraries(test.scratch.versions
		PRIVATE
			xTests::core
	)
endif()
