from __future__ import print_function
from flask import Flask, request, jsonify
from flask import render_template
import os
import subprocess

app = Flask(__name__)

@app.route("/process", methods=["POST"])
def process():
    obj = request.get_json(silent=True)
    print(obj)
    a = obj.get("a", "")
    b = obj.get("b", "")

    f = open("tmp.dat", "w+")
    f.write(a + "\n")
    f.write(b + "\n")
    f.close()

    # create an json object here and pass that object to ./a.out
    # https://docs.python.org/2/library/subprocess.html#popen-constructor
    proc = subprocess.Popen(["./a.out", "tmp.dat"], stdout=subprocess.PIPE)
    output = proc.communicate()[0] # communicate() returns a tuple (stdoutdata, stderrdata).
    print(output)

    # os.system('g++ add.cpp')
    # print(os.system('./a.out tmp.dat'))

    print("end")
    return jsonify(res = output)
    # return jsonify(a=a, b=b)

@app.route("/")
def home(name=None):
    #.get('code', '')
    # print(output)
    # os.system('g++ add.cpp')
    # os.system('./a.out data.in')
    # return "Hello World!\n"+output
    return render_template('page.html', name=name)

if __name__ == "__main__":
    app.run()
