vector_filter_test_srcs = [
  'vector-filter-test.c',
]
inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))
vector_filter_test_include_dirs = [
  '.',
  inc,
]
vector_filter_test_deps = [
  c_greatest_dep,
  c_vector_dep,
  vector_test_utils_dep,
]
vector_filter_test_c_args = [
]
vector_filter_test_link_args = [
]

vector_filter_test_test_dir = join_paths(meson.current_source_dir(), '..')

if get_option('enable-binaries')
  vector_filter_test_exec = executable('vector-filter-test',
     vector_filter_test_srcs,
     dependencies: vector_filter_test_deps,
     include_directories: vector_filter_test_include_dirs,
     link_args: vector_filter_test_link_args,
     c_args: vector_filter_test_c_args,
     install: false,
  )
  test('vector-filter-test', 
    vector_filter_test_exec, args: ['-v','-a'],
    workdir: vector_filter_test_test_dir,
  )
endif
