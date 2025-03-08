import subprocess
import sys

def run_make(command):
    try:
        subprocess.run(["make", command], check=True)
        print(f"Command 'make {command}' executed successfully.")
    except subprocess.CalledProcessError as e:
        print(f"Error executing 'make {command}': {e}")

def main():
    if len(sys.argv) != 2:
        print("Usage: python build.py [clean|make]")
        sys.exit(1)

    command = sys.argv[1]

    if command == "clean":
        run_make("clean")
    elif command == "make":
        run_make("")
    else:
        print("Invalid argument. Use 'clean' or 'make'.")
        sys.exit(1)

if __name__ == "__main__":
    main()