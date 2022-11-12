project('c_vector', ['c'],default_options: ['warning_level=0','c_std=gnu99',],subproject_dir: 'subprojects',version: '0.0.1')
cc = meson.get_compiler('c')
pwd = meson.current_source_dir()
c_deps_dir = join_paths(meson.current_source_dir(),'.')
make_program = find_program('make', required: true)
inc = [include_directories(
  '.',
  'vector',
  'vector-test',
  'submodules',
)]

#############################################################################
subdir('submodules')
subdir('vector')
#############################################################################
subdir('vector-test-utils')
#############################################################################
subdir('vector-basic-tests/clear-empty')
subdir('vector-basic-tests/clear-no-resize')
subdir('vector-basic-tests/clear-with-resize')
subdir('vector-basic-tests/ensure-capacity-bigger')
subdir('vector-basic-tests/ensure-capacity-same')
subdir('vector-basic-tests/ensure-capacity-smaller')
subdir('vector-basic-tests/get-data')
subdir('vector-basic-tests/get-empty')
subdir('vector-basic-tests/get-out-of-range')
subdir('vector-basic-tests/insert')
subdir('vector-basic-tests/new')
subdir('vector-basic-tests/new-with-options-no-resize')
subdir('vector-basic-tests/new-with-options-with-resize')
subdir('vector-basic-tests/pop-empty')
subdir('vector-basic-tests/pop-with-data')
subdir('vector-basic-tests/prepend')
subdir('vector-basic-tests/push-no-resize')
subdir('vector-basic-tests/push-unable-to-resize')
subdir('vector-basic-tests/push-with-resize')
subdir('vector-basic-tests/remove-empty')
subdir('vector-basic-tests/remove-out-of-range')
subdir('vector-basic-tests/remove-with-data')
subdir('vector-basic-tests/set')
subdir('vector-basic-tests/shrink-empty')
subdir('vector-basic-tests/shrink-not-empty')
subdir('vector-basic-tests/stability')
subdir('vector-basic-tests/to-array-empty')
subdir('vector-basic-tests/to-array-with-data')
#############################################################################
subdir('vector-test')
subdir('vector-for-each-test')
subdir('vector-filter-test')
subdir('vector-sort-test')
subdir('each-test')
