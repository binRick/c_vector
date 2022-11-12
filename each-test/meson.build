each_test_srcs = [
  'each-test.c',
]
inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))
each_test_include_dirs = [
  '.',
  inc,
]
each_test_deps = [
  c_greatest_dep,
  c_vector_dep,
]
each_test_c_args = [
]
each_test_link_args = [
]

each_test_test_dir = join_paths(meson.current_source_dir(), '..')

if get_option('enable-binaries')
  each_test_exec = executable('each-test',
     each_test_srcs,
     dependencies: each_test_deps,
     include_directories: each_test_include_dirs,
     link_args: each_test_link_args,
     c_args: each_test_c_args,
     install: false,
  )
  test('each-test', 
    each_test_exec, args: ['-v','-a'],
    workdir: each_test_test_dir,
  )
endif
