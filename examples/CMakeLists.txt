file(GLOB_RECURSE sanity_sources sanity/*.cpp sanity/*.h)
add_executable(sanity ${sanity_sources})
target_link_libraries(sanity lib)
target_include_directories(sanity PRIVATE ../src/)