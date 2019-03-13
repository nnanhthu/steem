
add_library( beowulf_jsonball
   mm_ticks.cpp
   rc_params.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/beowulf/jsonball/jsonball.hpp
)

target_link_libraries( beowulf_jsonball fc )

target_include_directories( beowulf_jsonball PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

INSTALL( TARGETS
   beowulf_jsonball

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)