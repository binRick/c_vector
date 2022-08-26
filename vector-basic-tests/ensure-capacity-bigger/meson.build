vector_basic_test_srcs = [
  'test_ensure-capacity-bigger.c',
]
inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))
vector_basic_test_include_dirs = [
  '.',
  inc,
]
vector_basic_test_deps = [
  c_greatest_dep,
  c_vector_dep,
  vector_test_utils_dep,
]
vector_basic_test_c_args = [
]
vector_basic_test_link_args = [
]

vector_basic_test_test_dir = join_paths(meson.current_source_dir(), '..')

if get_option('enable-binaries')
  vector_basic_test_exec = executable('ensure-capacity-bigger',
     vector_basic_test_srcs,
     dependencies: vector_basic_test_deps,
     include_directories: vector_basic_test_include_dirs,
     link_args: vector_basic_test_link_args,
     c_args: vector_basic_test_c_args,
     install: false,
  )
  test('ensure-capacity-bigger', 
    vector_basic_test_exec, args: ['-v','-a'],
    workdir: vector_basic_test_test_dir,
  )
endif
