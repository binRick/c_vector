vector_test_utils_srcs = [
  'vector-test-utils.c',
]
inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))
vector_test_utils_include_dirs = [
  '.',
  inc,
]
vector_test_utils_deps = [
  c_vector_dep,
]
vector_test_utils_c_args = [
]
vector_test_utils_link_args = [
]

vector_test_utils_test_dir = join_paths(meson.current_source_dir(), '..')

vector_test_utils_lib = static_library('vector-test-utils',
  vector_test_utils_srcs,
  install: false,
  dependencies: vector_test_utils_deps,
  c_args: vector_test_utils_c_args,
  include_directories: vector_test_utils_include_dirs,
)

vector_test_utils_dep = declare_dependency(
  include_directories: vector_test_utils_include_dirs,
  link_with: vector_test_utils_lib,
  link_args: vector_test_utils_link_args,
)

