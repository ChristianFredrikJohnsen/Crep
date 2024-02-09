import sys

def convert_path(win_path: str) -> str:
    """Converts a Windows path to a WSL path."""
    return win_path.replace("\\", "/").replace("C:", "/mnt/c")

if __name__ == "__main__":
    if len(sys.argv) > 1:
        print(convert_path(sys.argv[1]))
    else:
        print("Please provide a Windows path.")
