vector_test_srcs = [
  'vector-test.c',
]
inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))
vector_test_include_dirs = [
  '.',
  inc,
]
vector_test_deps = [
  c_greatest_dep,
  c_vector_dep,
  debug_memory_dep,
]
vector_test_c_args = [
]
vector_test_link_args = [
]

vector_test_test_dir = join_paths(meson.current_source_dir(), '..')

if get_option('enable-binaries')
  vector_test_exec = executable('vector-test',
     vector_test_srcs,
     dependencies: vector_test_deps,
     include_directories: vector_test_include_dirs,
     link_args: vector_test_link_args,
     c_args: vector_test_c_args,
     install: false,
  )
  #test('vector-test', 
  #  vector_test_exec, args: ['-v','-a'],
  #  workdir: vector_test_test_dir,
  #)
endif
