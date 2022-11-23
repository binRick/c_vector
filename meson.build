project('c_vector', ['c'],default_options: ['warning_level=0','c_std=gnu99',],subproject_dir: 'subprojects',version: '0.0.1')
cc = meson.get_compiler('c')
pwd = meson.current_source_dir()
c_deps_dir = join_paths(meson.current_source_dir(),'submodules/c_deps')
make_program = find_program('make', required: true)
pkg = import('pkgconfig')
inc = [include_directories(
  '.',
  'vector',
  'vector-test',
  'submodules/c_deps',
  'submodules/c_deps/submodules',
  'submodules',
)]
ck_dep = dependency('ck', method: 'pkg-config', required: true)
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



vector_installed_headers = [
  'vector/vector.h',
  'submodules/c_deps/submodules/ms/ms.h',
  'submodules/c_deps/submodules/log/log.h',
  'submodules/c_deps/submodules/log/log-print.h',
  'submodules/c_deps/submodules/bytes/bytes.h',
  'submodules/c_deps/submodules/timestamp/timestamp.h',
  'submodules/c_deps/submodules/tempdir.c/tempdir.h',
  'submodules/c_deps/submodules/c_stringfn/include/stringfn.h',
  'submodules/c_deps/submodules/c_string_buffer/include/stringbuffer.h',
  'submodules/c_deps/submodules/c_fsio/include/fsio.h',
  'submodules/c_deps/submodules/chan/src/chan.h',
  'submodules/c_deps/submodules/chan/src/queue.h',
  'submodules/c_deps/submodules/c_string_buffer/include/stringbuffer.h',
  'submodules/c_deps/submodules/c_stringfn/include/stringfn.h',
  'submodules/c_deps/submodules/hash/hash.h',
  'submodules/c_deps/submodules/hash/khash.h',
  'submodules/c_deps/submodules/module/module.h',
  'submodules/c_deps/submodules/module/require.h',
  'submodules/c_deps/submodules/module/def.h',
]

c_utils_libs = [
  c_stringfn_lib_static,
  c_fsio_lib_static,
  ms_lib_static,
  bytes_lib_static,
  c_string_buffer_lib_static,
  log_lib_static,
  timestamp_lib_static,
  chan_lib_static,
  tempdir_lib_static,
  hash_lib_static,
  asprintf_lib_static,
  c_vector_lib_static,
]
c_utils_lib = static_library('cu',
  [],
  install: true,
  link_whole: c_utils_libs,
  c_args: [],
)
install_headers(vector_installed_headers)

import('pkgconfig').generate(c_utils_lib,
  subdirs: '.',
  name: 'libcu',
  filebase: 'cu',
  description: 'c utils',
  )
