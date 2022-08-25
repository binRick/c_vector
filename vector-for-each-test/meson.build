vector_for_each_test_srcs = [
  'vector-for-each-test.c',
]
inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))
vector_for_each_test_include_dirs = [
  '.',
  inc,
]
vector_for_each_test_deps = [
  c_greatest_dep,
  c_vector_dep,
]
vector_for_each_test_c_args = [
]
vector_for_each_test_link_args = [
]

vector_for_each_test_test_dir = join_paths(meson.current_source_dir(), '..')

if get_option('enable-binaries')
  vector_for_each_test_exec = executable('vector-for-each-test',
     vector_for_each_test_srcs,
     dependencies: vector_for_each_test_deps,
     include_directories: vector_for_each_test_include_dirs,
     link_args: vector_for_each_test_link_args,
     c_args: vector_for_each_test_c_args,
     install: false,
  )
  #test('vector-for-each-test', 
  #  vector_for_each_test_exec, args: ['-v','-a'],
  #  workdir: vector_for_each_test_test_dir,
  #)
endif
