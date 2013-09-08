
{
    "targets": [
        {
            "target_name": "mmseg",
            "sources": [
                "mmseg.cc"
            ],
            "include_dirs": [
                "/usr/local/include/mmseg/"
            ],
            "cflags_cc": [
                "-fPIC", "-O2", "-pthread",
                "-finline", "-finline-small-functions",
                "-fomit-frame-pointer", "-momit-leaf-frame-pointer",
                "-Wno-unused-function"
            ],
            "defines": ["NDEBUG"],
            "conditions": [
                [
                    "OS!='win'",
                    {
                        "link_settings": {
                            "ldflags": ["-Wl,-O3"],
                            "libraries": ["-lmmseg"]
                        }
                    }
                ]
            ]
        }
    ]
}

