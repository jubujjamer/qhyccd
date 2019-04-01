import ctypes

lib = ctypes.CDLL('../build/lib.so')
print(lib.init_resource())
cams = lib.scan_cameras()
print()
idx = ctypes.c_int(0)
lib.get_camera_id.restype = ctypes.c_char_p
cam_id = lib.get_camera_id(idx)
print('Camera Id is %s' %cam_id)
# lib.open_camera.restype = ctypes.c_char_p
lib.open_camera.restype = ctypes.c_void_p
cam_handle = lib.open_camera(cam_id)
cam_mode = 0
lib.set_stream_mode.argtypes = [ctypes.c_void_p, ctypes.c_int]
print(lib.set_stream_mode(cam_handle, cam_mode))
