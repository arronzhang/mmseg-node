#MMSEG_PATH
import os
srcdir = "."
blddir = "build"
VERSION = "0.0.1"

def set_options(opt):
  opt.tool_options("compiler_cxx")

def configure(conf):
  mmsegpath = os.environ.get('MMSEG_PATH')
  libpath = ['/usr/lib', '/usr/local/lib']
  if mmsegpath != None:
    libpath.append('/'.join([mmsegpath,'lib']))
  conf.check_tool("compiler_cxx")
  conf.check_tool("node_addon")
  conf.check(lib='stdc++', libpath=['/usr/lib', '/usr/local/lib'], uselib_store='LIBSTDC')
  conf.check(lib='mmseg', libpath=libpath, uselib_store='LIBMMSEG')
  conf.env.append_value('CCFLAGS', ['-O3'])

def build(bld):
  mmsegpath = os.environ.get('MMSEG_PATH')
  includepath = ["/usr/local/include/mmseg"]
  if mmsegpath != None:
    includepath.append('/'.join([mmsegpath,'include']))
  obj = bld.new_task_gen("cxx", "shlib", "node_addon")
  obj.target = "mmseg"
  obj.source = "mmseg.cc"
  obj.uselib = ["LIBSTDC", "LIBMMSEG"]
  obj.includes = includepath
