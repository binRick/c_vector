project('c_vector', ['c'],default_options: ['warning_level=0','c_std=gnu99',],subproject_dir: 'submodules/c_deps/subprojects',version: '0.0.1')
cc = meson.get_compiler('c')
pwd = meson.current_source_dir()
c_deps_dir = join_paths(meson.current_source_dir(),'submodules/c_deps')
make_program = find_program('make', required: true)
inc = [include_directories(
  '.',
  'vector',
  'vector-test',
  'submodules/c_deps',
  'submodules/c_deps/submodules',
)]
#############################################################################
subdir('vector')
#############################################################################
subdir('submodules')
#############################################################################
subdir('vector-test-utils')
subdir('vector-test')
subdir('vector-for-each-test')
subdir('vector-filter-test')
#############################################################################
