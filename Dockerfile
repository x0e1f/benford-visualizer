FROM emscripten/emsdk AS wasm_builder
WORKDIR /opt/benford
COPY benford .
RUN make

FROM node AS npm_builder
WORKDIR /opt/app
COPY app/package.json .
RUN npm install

FROM nginx
WORKDIR /usr/share/nginx/html
COPY app .
COPY --from=wasm_builder /opt/benford/dist/benford.js ./assets/js/benford.js
COPY --from=wasm_builder /opt/benford/dist/benford.wasm ./assets/js/benford.wasm
COPY --from=npm_builder /opt/app/node_modules ./node_modules
