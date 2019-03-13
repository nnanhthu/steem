file(GLOB HEADERS "include/beowulf/chain/*.hpp" "include/beowulf/chain/util/*.hpp" "include/beowulf/chain/smt_objects/*.hpp")

## SORT .cpp by most likely to change / break compile
add_library( beowulf_chain

             # As database takes the longest to compile, start it first
             database.cpp

             smt_evaluator.cpp
             smt_objects/smt_market_maker.cpp
             smt_objects/nai_pool.cpp
             beowulf_evaluator.cpp
             beowulf_objects.cpp

             witness_schedule.cpp
             fork_database.cpp

             shared_authority.cpp
             block_log.cpp

             generic_custom_operation_interpreter.cpp

             util/rd.cpp
             util/reward.cpp
             util/impacted.cpp
             util/advanced_benchmark_dumper.cpp
             util/smt_token.cpp

             ${HEADERS}
           )

target_link_libraries( beowulf_chain beowulf_jsonball beowulf_protocol fc chainbase beowulf_schema appbase
                       ${PATCH_MERGE_LIB} )
target_include_directories( beowulf_chain
                            PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_BINARY_DIR}/include" )

if( CLANG_TIDY_EXE )
   set_target_properties(
      beowulf_chain PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

if(MSVC)
  set_source_files_properties( database.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   beowulf_chain

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/beowulf/chain" )
