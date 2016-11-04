from __future__ import print_function
from flask import Flask, request, jsonify
from flask import render_template
import os
import subprocess
app = Flask(__name__)

@app.route("/hello2", methods=["POST"])
def hello2():
    obj = request.get_json(silent=True)
    print(obj)
    a = obj.get("a", "")
    b = obj.get("b", "")
    print(a, b)
    # return "Test"
    return jsonify(a=a, b=b)

@app.route("/")
def hello(name=None):
    #.get('code', '')
    proc = subprocess.Popen(["./a.out", "data.in"], stdout=subprocess.PIPE)
    output = proc.communicate()[0]
    # print(output)
    # os.system('g++ add.cpp')
    # os.system('./a.out data.in')
    # return "Hello World!\n"+output
    return render_template('hello.html', name=name)

if __name__ == "__main__":
    app.run()