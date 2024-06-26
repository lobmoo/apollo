# 概述

在 Apollo 9.0 中，对规划模块进行了插件化重构，根据开发者的使用场景，提供了多种开发模式。

当 Apollo 的现有功能和业务逻辑完全适用于您的场景，可以不需要开发代码，只通过调整规划模块配置参数实现场景的功能需求。比如，您只希望点到点行驶调整巡航速度，或者转弯是期望速度更低。配置参数包括了规划任务的参数文件以及场景参数文件，将在 [通过配置参数开发](Apollo_alpha_doc/使用指南/核心模块/规划能力/开发模式/通过配置参数开发.md) 中详细说明。

当您的场景需要自由编排规划任务和其他功能模块共同完成作业，比如，无人配送场景，需要用户取走快递后再执行下个点到点沿车道行驶任务，矿山场景中循环执行装载卸载任务；或者需要在规划模块运行过程中执行一些临时动作，比如在行驶过程中需要临时控制车辆速度，或者临时靠边停车，可以采用对规划模块发布命令方式实现，将在 [通过发布命令开发](Apollo_alpha_doc/使用指南/核心模块/规划能力/开发模式/通过发布命令开发.md) 详细说明。

当 Apollo 现有功能和业务逻辑无法满足您的场景需求，比如您需要控制的车辆无法用前轮转向的车辆模型表述，您可以通过对规划模块二次开发实现您的场景需求，将在 [通过新增插件开发](Apollo_alpha_doc/使用指南/核心模块/规划能力/开发模式/通过新增插件开发.md) 中详细说明。
