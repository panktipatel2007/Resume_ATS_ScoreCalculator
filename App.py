from flask import Flask, render_template, request, send_file
import subprocess

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/analyze', methods=['POST'])
def analyze():
    jd = request.form['jd']
    resume_text = request.form['resume_text']

    result = subprocess.run(
        ['./analyzer', resume_text, jd],
        capture_output=True,
        text=True
    )

    score = float(result.stdout.strip()) if result.stdout.strip() else 0

    feedback = {
        "score": round(score, 2)
    }

    return render_template('index.html', result=feedback)
if __name__ == '__main__':
    app.run(debug=True)