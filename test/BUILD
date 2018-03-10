load("@UnityTestRunnerGeneration//:unity_helpers.bzl", "generate_a_unity_test_for_every_file")

generate_a_unity_test_for_every_file(
    file_list = glob(["*_Test.c"]),
    deps = [
        "//lib:UnityOutput",
    ],
)
