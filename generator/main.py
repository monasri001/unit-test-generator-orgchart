import os
import subprocess

def load_prompt(yaml_path):
    with open(yaml_path, 'r') as f:
        return f.read()

def run_ollama(code, prompt):
    full_prompt = prompt + "\n\n```cpp\n" + code + "\n```"
    result = subprocess.run(
        ["ollama", "run", "llama3"],
        input=full_prompt.encode(),
        capture_output=True
    )
    return result.stdout.decode()

def generate_tests(source_dir, output_dir, prompt_file):
    prompt = load_prompt(prompt_file)
    os.makedirs(output_dir, exist_ok=True)

    for root, _, files in os.walk(source_dir):
        for file in files:
            if file.endswith(".cc") or file.endswith(".h"):
                full_path = os.path.join(root, file)
                with open(full_path, 'r') as src_file:
                    code = src_file.read()
                
                print(f"🔹 Generating tests for: {file}")
                output = run_ollama(code, prompt)

                out_file = os.path.join(output_dir, f"test_{file}")
                with open(out_file, 'w') as f:
                    f.write(output)

                print(f"✅ Test saved to: {out_file}")

generate_tests("orgChartApi-master", "tests_generated", "prompts/unit_test.yaml")
