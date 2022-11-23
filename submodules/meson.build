##subdir('c_deps/meson/osx')
#subdir('timestamp')
#subdir('c_deps/meson/deps/cargs')
subdir('c_deps/meson/deps/strdup')
subdir('c_deps/meson/deps/module')
#subdir('c_deps/meson/deps/str-flatten.c')
#subdir('c_deps/meson/deps/vt100utils')
subdir('c_deps/meson/deps/uuid4')
subdir('c_deps/meson/deps/chan')
subdir('c_deps/meson/deps/timestamp')
subdir('c_deps/meson/deps/asprintf')
subdir('c_deps/meson/deps/hash')
#subdir('c_deps/meson/deps/progress')
subdir('c_deps/meson/deps/wildcardcmp')
subdir('c_deps/meson/deps/tempdir')
subdir('c_deps/meson/deps/c_string_buffer')
subdir('c_deps/meson/deps/c_stringfn')
subdir('c_deps/meson/deps/c_fsio')
subdir('c_deps/meson/deps/c_forever')
subdir('c_deps/meson/deps/parson')
subdir('c_deps/meson/deps/bytes')
#subdir('c_deps/meson/deps/c_greatest')
#subdir('c_deps/meson/deps/debug-memory')
subdir('c_deps/meson/deps/log')
#subdir('c_deps/meson/deps/c_dbg')
#subdir('c_deps/meson/deps/env.h')
#subdir('c_deps/meson/deps/throw.h')
subdir('c_deps/meson/deps/ms')
#subdir('c_deps/meson/deps/hidapi')
#subdir('c_deps/submodules/c_ansi/ansi-codes')
c_greatest_system_headers = [

]
c_greatest_local_headers = [
  'c_greatest/greatest/greatest.h',
]
c_greatest_srcs = [

]

c_greatest_dirs = [
  '../submodules/c_greatest',
  inc,
]

c_greatest_deps = [

]

if c_greatest_srcs.length() > 0
  c_greatest_lib =library('c_greatest',
    files(c_greatest_srcs),
    install: false,
    dependencies: c_greatest_deps,
    include_directories: c_greatest_dirs,
  )
  c_greatest_links = [c_greatest_lib]
else
  c_greatest_links = []
endif

c_greatest_dep = declare_dependency(
  include_directories: c_greatest_dirs,
  link_with: c_greatest_links,
)
module_dep = declare_dependency(
  include_directories: [
    '../submodules/module',
  ],
  link_with: [],
)
