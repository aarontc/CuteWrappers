set(
	CuteWrappers_Sources

	CuteSettings.cpp
)

set(
	CuteWrappers_Headers

	CuteSettings.h
)

set(
	CuteWrappers_Forms
)

qt4_wrap_cpp(CuteWrappers_Sources ${CuteWrappers_Headers})
qt4_wrap_ui(CuteWrappers_Sources ${CuteWrappers_Forms})


add_library(
	CuteWrappers
	SHARED

	${CuteWrappers_Sources}
)

target_link_libraries(
	CuteWrappers
	${QT_LIBRARIES}
)


install(TARGETS CuteWrappers
	LIBRARY DESTINATION lib COMPONENT libraries
	ARCHIVE DESTINATION lib COMPONENT libraries
)

# Fixme HACK this gets the headers to the right place on Linux... probably not Windows?
install(
	FILES
	${CuteWrappers_Headers}
	DESTINATION include/CuteWrappers
)
