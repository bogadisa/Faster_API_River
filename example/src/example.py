def use_example():
    import spam

    status = spam.system("echo done")


def use_example_yt():
    import c_add

    x = 1
    y = 2
    z = c_add.add(1, 2)

    print(f"x + y = {z}")


use_example()
use_example_yt()
