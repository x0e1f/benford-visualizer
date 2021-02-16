# Benford Visualizer <img src="app/favicon.ico" width=30px>

![Project header](header.png)

Since I first came accross the Benford's Law I began to be really curious in testing any datasets I can think of against it. For this reason and due to the fact that i wanted to test webassembly with c++ and emscripten I did this simple project. In order to use benford-visualizer just run the docker image and open a browser on http://localhost:8080, you will be able to modify the dataset in any way you want and see the chart updating in real time.

## Running with Docker
Build docker image
```
docker build -t benford-visualizer . 
```
Run benford-visualizer image on port 8080

```
docker run --name benford-visualizer -d -p 8080:80 benford-visualizer 
```

## License

The MIT License (MIT)

Copyright (c) 2021 Davide Pataracchia

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.