/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Microsoft Corporation. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
"use strict";function onError(e,t){t&&ipc.send("vscode:openDevTools"),console.error("[uncaught exception]: "+e),e.stack&&console.error(e.stack)}function assign(e,t){return Object.keys(t).reduce(function(e,o){return e[o]=t[o],e},e)}function parseURLQueryArgs(){return(window.location.search||"").split(/[?&]/).filter(function(e){return!!e}).map(function(e){return e.split("=")}).filter(function(e){return 2===e.length}).reduce(function(e,t){return e[t[0]]=decodeURIComponent(t[1]),e},{})}function uriFromPath(e){var t=path.resolve(e).replace(/\\/g,"/");return t.length>0&&"/"!==t.charAt(0)&&(t="/"+t),encodeURI("file://"+t).replace(/#/g,"%23")}function readFile(e){return new Promise(function(t,o){fs.readFile(e,"utf8",function(e,r){e?o(e):t(r)})})}function writeFile(e,t){return new Promise((o,r)=>fs.writeFile(e,t,"utf8",e=>e?r(e):o()))}function showPartsSplash(e){perf.mark("willShowPartsSplash"),perf.mark("willAccessLocalStorage");let t=window.localStorage;perf.mark("didAccessLocalStorage");let o;try{
let e=t.getItem("storage://global/parts-splash-data");o=JSON.parse(e)}catch(e){}o&&e.highContrast&&"hc-black"!==o.baseTheme&&(o=void 0);const r=document.createElement("style");if(document.head.appendChild(r),o){const{layoutInfo:t,colorInfo:n,baseTheme:i}=o;document.body.className=`monaco-shell ${i}`,r.innerHTML=`.monaco-shell { background-color: ${n.editorBackground}; color: ${n.foreground}; }`;const a=document.createElement("div");a.id=o.id,t.sideBarWidth=Math.min(t.sideBarWidth,window.innerWidth-(t.activityBarWidth+t.editorPartMinWidth)),
e.folderUri||e.workspace?a.innerHTML=`\n\t\t\t<div style="position: absolute; width: 100%; left: 0; top: 0; height: ${t.titleBarHeight}px; background-color: ${n.titleBarBackground};"></div>\n\t\t\t<div style="position: absolute; height: calc(100% - ${t.titleBarHeight}px); top: ${t.titleBarHeight}px; ${t.sideBarSide}: 0; width: ${t.activityBarWidth}px; background-color: ${n.activityBarBackground};"></div>\n\t\t\t<div style="position: absolute; height: calc(100% - ${t.titleBarHeight}px); top: ${t.titleBarHeight}px; ${t.sideBarSide}: ${t.activityBarWidth}px; width: ${t.sideBarWidth}px; background-color: ${n.sideBarBackground};"></div>\n\t\t\t<div style="position: absolute; width: 100%; bottom: 0; left: 0; height: ${t.statusBarHeight}px; background-color: ${n.statusBarBackground};"></div>\n\t\t\t`:a.innerHTML=`\n\t\t\t<div style="position: absolute; width: 100%; left: 0; top: 0; height: ${t.titleBarHeight}px; background-color: ${n.titleBarBackground};"></div>\n\t\t\t<div style="position: absolute; height: calc(100% - ${t.titleBarHeight}px); top: ${t.titleBarHeight}px; ${t.sideBarSide}: 0; width: ${t.activityBarWidth}px; background-color: ${n.activityBarBackground};"></div>\n\t\t\t<div style="position: absolute; width: 100%; bottom: 0; left: 0; height: ${t.statusBarHeight}px; background-color: ${n.statusBarNoFolderBackground};"></div>\n\t\t\t`,
document.body.appendChild(a)}else document.body.className=`monaco-shell ${e.highContrast?"hc-black":"vs-dark"}`,r.innerHTML=`.monaco-shell { background-color: ${e.highContrast?"#000000":"#1E1E1E"}; color: ${e.highContrast?"#FFFFFF":"#CCCCCC"}; }`;perf.mark("didShowPartsSplash")}function registerListeners(e){var t;if(e){const e="darwin"===process.platform?"meta-alt-73":"ctrl-shift-73",o="darwin"===process.platform?"meta-82":"ctrl-82";t=function(t){const r=function(e){return[e.ctrlKey?"ctrl-":"",e.metaKey?"meta-":"",e.altKey?"alt-":"",e.shiftKey?"shift-":"",e.keyCode].join("")}(t);r===e?ipc.send("vscode:toggleDevTools"):r===o&&ipc.send("vscode:reloadWindow")},window.addEventListener("keydown",t)}return process.on("uncaughtException",function(t){onError(t,e)}),function(){t&&(window.removeEventListener("keydown",t),t=void 0)}}function main(){const e=require("electron").webFrame,t=parseURLQueryArgs(),o=JSON.parse(t.config||"{}")||{};!function(){const e=require("path"),t=require("module")
;let r=e.join(o.appRoot,"node_modules");/[a-z]\:/.test(r)&&(r=r.charAt(0).toUpperCase()+r.substr(1));const n=r+".asar",i=t._resolveLookupPaths;t._resolveLookupPaths=function(e,t,o){const a=i(e,t,o),s=o?a:a[1];for(let e=0,t=s.length;e<t;e++)if(s[e]===r){s.splice(e,0,n);break}return a}}(),assign(process.env,o.userEnv);const r=o.zoomLevel;e.setVisualZoomLevelLimits(1,1),"number"==typeof r&&0!==r&&e.setZoomLevel(r),showPartsSplash(o);var n={availableLanguages:{}};const i=process.env.VSCODE_NLS_CONFIG;if(i){process.env.VSCODE_NLS_CONFIG=i;try{n=JSON.parse(i)}catch(e){}}if(n._resolvedLanguagePackCoreLocation){let e=Object.create(null);n.loadBundle=function(t,o,r){let i=e[t];if(i)return void r(void 0,i);readFile(path.join(n._resolvedLanguagePackCoreLocation,t.replace(/\//g,"!")+".nls.json")).then(function(o){let n=JSON.parse(o);e[t]=n,r(void 0,n)}).catch(e=>{try{n._corruptedFile&&writeFile(n._corruptedFile,"corrupted").catch(function(e){console.error(e)})}finally{r(e,void 0)}})}}var a=n.availableLanguages["*"]||"en"
;"zh-tw"===a?a="zh-Hant":"zh-cn"===a&&(a="zh-Hans"),window.document.documentElement.setAttribute("lang",a);const s=(process.env.VSCODE_DEV||!!o.extensionDevelopmentPath)&&!o.extensionTestsPath,c=registerListeners(s),l=o.appRoot+"/out/vs/loader.js",d=require("fs").readFileSync(l);require("vm").runInThisContext(d,{filename:l});var p=global.define;global.define=void 0,window.nodeRequire=require.__$__nodeRequire,p("fs",["original-fs"],function(e){return e}),window.MonacoEnvironment={};const u=window.MonacoEnvironment.onNodeCachedData=[];require.config({baseUrl:uriFromPath(o.appRoot)+"/out","vs/nls":n,recordStats:!!o.performance,nodeCachedDataDir:o.nodeCachedDataDir,onNodeCachedData:function(){u.push(arguments)},
nodeModules:["electron","original-fs","vsda","nan","readable-stream","strip-ansi","applicationinsights","fast-plist","gc-signals","getmac","graceful-fs","http-proxy-agent","debug","https-proxy-agent","iconv-lite","jschardet","keytar","minimist","native-is-elevated","native-keymap","native-watchdog","node-pty","semver","spdlog","sudo-prompt","v8-inspect-profiler","vscode-chokidar","vscode-fsevents","vscode-debugprotocol","vscode-nsfw","vscode-ripgrep","vscode-textmate","vscode-xterm","vsda","winreg","yauzl","yazl","windows-foreground-love","windows-mutex","windows-process-tree","agent-base","ansi-regex","async-each","bindings","buffer-crc32","chrome-remote-interface","core-util-is","ms","editions","extract-opts","fd-slicer","fs-extra","glob-parent","inherits","is-binary-path","is-glob","isarray","lodash.isinteger","lodash.isundefined","mkdirp","oniguruma","path-is-absolute","prebuild-install","github-from-package","process-nextick-args","promisify-node","readdirp","string_decoder","safe-buffer","safer-buffer","util-deprecate","vscode-anymatch","binary-extensions","commander","detect-libc","eachr","es6-promisify","expand-template","is-extglob","jsonfile","klaw","micromatch","normalize-path","minimatch","node-abi","nodegit-promise","noop-logger","npmlog","os-homedir","pend","pump","rc","rimraf","set-immediate-shim","simple-get","tar-fs","tunnel-agent","typechecker","which-pm-runs","ws","are-we-there-yet","arr-diff","array-unique","asap","async-limiter","brace-expansion","concat-map","braces","chownr","console-control-strings","decompress-response","deep-extend","end-of-stream","es6-promise","expand-brackets","extglob","filename-regex","gauge","glob","ini","kind-of","object.omit","once","parse-glob","regex-cache","remove-trailing-separator","set-blocking","simple-concat","strip-json-comments","tar-stream","ultron","aproba","arr-flatten","balanced-match","bl","buffer-alloc","delegates","expand-range","for-own","fs-constants","fs.realpath","glob-base","has-unicode","inflight","is-buffer","is-dotfile","is-equal-shallow","is-extendable","is-posix-bracket","is-primitive","mimic-response","object-assign","preserve","repeat-element","signal-exit","string-width","to-buffer","wide-align","is-fullwidth-code-point","wrappy","xtend","buffer-alloc-unsafe","buffer-fill","code-point-at","fill-range","for-in","is-number","isobject","number-is-nan","randomatic","repeat-string","async_hooks","assert","buffer","child_process","console","constants","crypto","cluster","dgram","dns","domain","events","fs","http","http2","https","inspector","module","net","os","path","perf_hooks","process","punycode","querystring","readline","repl","stream","string_decoder","sys","timers","tls","tty","url","util","v8","vm","zlib"]
}),n.pseudo&&require(["vs/nls"],function(e){e.setPseudoTranslation(n.pseudo)}),perf.mark("willLoadWorkbenchMain"),require(["vs/workbench/workbench.main","vs/nls!vs/workbench/workbench.main","vs/css!vs/workbench/workbench.main"],function(){perf.mark("didLoadWorkbenchMain"),process.lazyEnv.then(function(){perf.mark("main/startup"),require("vs/workbench/electron-browser/main").startup(o).done(function(){c()},function(e){onError(e,s)})})})}const perf=require("../../../base/common/performance");perf.mark("renderer/started");const path=require("path"),fs=require("fs"),electron=require("electron"),ipc=electron.ipcRenderer;Error.stackTraceLimit=100,process.lazyEnv=new Promise(function(e){const t=setTimeout(function(){e(),console.warn("renderer did not receive lazyEnv in time")},1e4);ipc.once("vscode:acceptShellEnv",function(o,r){clearTimeout(t),assign(process.env,r),e(process.env)}),ipc.send("vscode:fetchShellEnv")}),main();
//# sourceMappingURL=https://ticino.blob.core.windows.net/sourcemaps/f46c4c469d6e6d8c46f268d1553c5dc4b475840f/core/vs\workbench\electron-browser\bootstrap\index.js.map
