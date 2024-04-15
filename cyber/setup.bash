#! /usr/bin/env bash
TOP_DIR="$(cd "$( dirname "${BASH_SOURCE[0]}" )/.." && pwd -P)"
source ${TOP_DIR}/scripts/apollo.bashrc

export APOLLO_BAZEL_DIST_DIR="${APOLLO_CACHE_DIR}/distdir"
export CYBER_PATH="${APOLLO_ROOT_DIR}/cyber"

bazel_bin_path="${APOLLO_ROOT_DIR}/bazel-bin"
mainboard_path="${bazel_bin_path}/cyber/mainboard"
cyber_tool_path="${bazel_bin_path}/cyber/tools"
recorder_path="${cyber_tool_path}/cyber_recorder"
launch_path="${cyber_tool_path}/cyber_launch"
channel_path="${cyber_tool_path}/cyber_channel"
node_path="${cyber_tool_path}/cyber_node"
service_path="${cyber_tool_path}/cyber_service"
monitor_path="${cyber_tool_path}/cyber_monitor"
visualizer_path="${bazel_bin_path}/modules/tools/visualizer"

# TODO(all): place all these in one place and pathprepend
for entry in "${mainboard_path}" \
    "${recorder_path}" "${monitor_path}"  \
    "${channel_path}" "${node_path}" \
    "${service_path}" \
    "${launch_path}" \
    "${visualizer_path}" ; do
    pathprepend "${entry}"
done

pathprepend ${bazel_bin_path}/cyber/python/internal PYTHONPATH
pathprepend "${PYTHON_INSTALL_PATH}/lib/python${PYTHON_VERSION}/site-packages" PYTHONPATH
pathprepend "${PYTHON_INSTALL_PATH}/bin/" PATH


if ! "${APOLLO_IN_DOCKER}" && \
    [ "${platform}" == "x86_64" ] && \
    ! grep -q "11th Gen Intel(R) Core(TM) i7-1165G7" <<< "$CPU_MODEL"; then
    export LD_LIBRARY_PATH=/apollo/third_party/fastrtps/x86_64_lib:$LD_LIBRARY_PATH   
elif [ "${platform}" == "aarch64" ]; then
    export LD_LIBRARY_PATH=/apollo/third_party/fastrtps/aarch64_lib:$LD_LIBRARY_PATH 
else
#movex
    export LD_LIBRARY_PATH=/apollo/third_party/fastrtps/x86_64_lib:$LD_LIBRARY_PATH     
fi


export CYBER_DOMAIN_ID=80
export CYBER_IP=127.0.0.1

export GLOG_log_dir="${APOLLO_ROOT_DIR}/data/log"
export GLOG_alsologtostderr=0
export GLOG_colorlogtostderr=1
export GLOG_minloglevel=0

export sysmo_start=0

# for DEBUG log
#export GLOG_v=4

source ${CYBER_PATH}/tools/cyber_tools_auto_complete.bash
