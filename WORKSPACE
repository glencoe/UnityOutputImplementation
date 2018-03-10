workspace(
	name = "UnityOutput"
		)

new_http_archive(
  name = "unity",
  urls = ["https://github.com/ThrowTheSwitch/Unity/archive/master.tar.gz"],
  build_file= "BUILD.unity",
  strip_prefix = "Unity-master",
  )

local_repository(
    name = "AVR_Toolchain",
    path = "/home/luk/Work/AVR-Toolchain",
    )

local_repository(
    name = "UnityTestRunnerGeneration",
    path = "/home/luk/Work/BazelUnityTestGeneration",
    )
