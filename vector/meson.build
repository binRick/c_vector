c_vector_srcs = [
  'vector.c',
]
inc = get_variable('inc', join_paths(meson.current_source_dir(),'..'))
c_vector_dirs = [
  include_directories('.','../'),
  inc,
]
c_vector_deps = [
  #hash_dep,
]
c_vector_libs = [
  ]
c_vector_c_args = [
  #//  '--no-unused-but-set-variable',
]
c_vector_link_args = [
]

c_vector_dir = join_paths(meson.current_source_dir(), '..')
c_vector_lib_static = static_library('vector',
  c_vector_srcs,
  install: false,
  dependencies: c_vector_deps,
  include_directories: c_vector_dirs,
  c_args: c_vector_c_args,
)
c_vector_lib = library('vector',
  c_vector_srcs,
  install: false,
  dependencies: c_vector_deps,
  include_directories: c_vector_dirs,
  c_args: c_vector_c_args,
)
c_vector_dep = declare_dependency(
  include_directories: c_vector_dirs,
  link_with: [c_vector_lib],
  link_args: c_vector_link_args,
)

